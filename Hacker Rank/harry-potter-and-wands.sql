SELECT
	T2.id,
	T2.age,
	T2.coins_needed,
	T2.power
FROM
	(
		SELECT
			Wands_Property.age AS age,
			MIN(Wands.coins_needed) AS coins_needed,
			Wands.power AS power
		FROM
			Wands
				INNER JOIN
					Wands_Property
				ON
					Wands_Property.code = Wands.code
		WHERE
			Wands_Property.is_evil = 0
		GROUP BY
			Wands.power,
			Wands_Property.age
	) AS T1
	INNER JOIN
	(
		SELECT
			Wands.id AS id,
			MIN(Wands.coins_needed) AS coins_needed,
			Wands_Property.age AS age,
			Wands.power AS power
		FROM
			Wands
				INNER JOIN
					Wands_Property
				ON
					Wands.code = Wands_Property.code
		WHERE
			Wands_Property.is_evil = 0
		GROUP BY
			Wands.power,
			Wands_Property.age,
			Wands.id
	) AS T2
	ON
		T1.coins_needed = T2.coins_needed AND
		T1.power = T2.power AND
		T1.age = T2.age
ORDER BY
	T2.power DESC,
	T2.age DESC
