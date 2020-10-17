SELECT
	Hackers.hacker_id,
	Hackers.name,
	SUM(T1.max_score) AS total_score
FROM
	Hackers
		INNER JOIN
			(
				SELECT
					Submissions.hacker_id,
					MAX(Submissions.score) AS max_score
				FROM
					Submissions
				GROUP BY
					Submissions.challenge_id,
					Submissions.hacker_id
			) AS T1
		ON
			Hackers.hacker_id = T1.hacker_id
GROUP BY
	Hackers.hacker_id,
	Hackers.name
HAVING
	total_score > 0
ORDER BY
	total_score DESC,
	Hackers.hacker_id ASC
