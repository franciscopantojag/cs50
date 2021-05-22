import os
import json
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, session, request, make_response
from helpers import validateForm

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        response = make_response(redirect("/"))
        name = request.form.get('name')
        month = request.form.get('month')
        day = request.form.get('day')
        errors = validateForm(name, month, day)
        oldValues = {
            'name': name,
            'month': month,
            'day': day
        }
        if bool(errors):
            # hay error
            response.set_cookie('errors', json.dumps(errors))
            response.set_cookie('oldValues', json.dumps(oldValues))
            return response
        db.execute(
            'INSERT INTO birthdays(name, month, day) VALUES(?, ?, ?)', name, month, day)
        return response
    context = {}
    errors = request.cookies.get('errors')
    birthdays = db.execute('SELECT * FROM birthdays')
    oldValues = request.cookies.get('oldValues')
    if isinstance(errors, str):
        context['errors'] = json.loads(errors)
    if(isinstance(oldValues, str)):
        context['oldValues'] = json.loads(oldValues)
    context['birthdays'] = birthdays
    response = make_response(
        render_template("index.html", context=context))
    if 'errors' in context:
        response.set_cookie('errors', expires=0)
    if 'oldValues' in context:
        response.set_cookie('oldValues', expires=0)
    return response


@app.route("/delete/<id>", methods=["POST"])
def delete(id):
    if id:
        db.execute(f'DELETE FROM birthdays WHERE id = {id}')
    return redirect("/")
