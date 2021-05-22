SELECT m.title FROM movies m, ratings r WHERE m.id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Chadwick Boseman")) AND r.movie_id = m.id ORDER BY r.rating DESC LIMIT 5;