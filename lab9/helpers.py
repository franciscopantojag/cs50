def numToStr(num):
    return str(num)


monthsDate = list(map(numToStr, list(range(1, 13))))
daysDate = list(map(numToStr, list(range(1, 32))))


def validateForm(name, month, day):
    errors = {}
    if not name:
        errors["name"] = 'empty'
    if not month:
        errors['month'] = 'empty'
    elif month not in monthsDate:
        errors['month'] = 'invalid value'
    if not day:
        errors['day'] = 'empty'
    elif day not in daysDate:
        errors['day'] = 'invalid value'
    return errors
