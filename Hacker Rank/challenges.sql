SELECT
	Hackers.hacker_id,
	Hackers.name,
	COUNT(Challenges.challenge_id) AS challenges_count
FROM
	Hackers
		INNER JOIN
			Challenges
		ON
			Hackers.hacker_id = Challenges.hacker_id
GROUP BY
	Hackers.hacker_id,
	Hackers.name
HAVING

	--  challenges_count = Max num of challenges by any user
	challenges_count = (
		SELECT
			COUNT(Challenges.challenge_id) AS challenges_count
		FROM
			Challenges
		GROUP BY
			Challenges.hacker_id
		ORDER BY
			challenges_count DESC
		LIMIT 1
	) OR

	-- challenges_count number is unique in the set
	challenges_count IN
		(
			SELECT
				T1.challenges_count
			FROM
				(
					SELECT
						Hackers.hacker_id,
						Hackers.name,
						COUNT(Challenges.challenge_id) AS challenges_count
					FROM
						Hackers
							INNER JOIN
								Challenges
							ON
								Hackers.hacker_id = Challenges.hacker_id
					GROUP BY
						Hackers.hacker_id,
						Hackers.name
				) AS T1
			GROUP BY
				T1.challenges_count
			HAVING
				COUNT(T1.challenges_count) = 1
		)


ORDER BY
	challenges_count DESC,
	Hackers.hacker_id ASC
