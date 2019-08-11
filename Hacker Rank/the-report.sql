SELECT
	IF (Grades.Grade < 8,
		"NULL", Students.Name) AS Name,
	Grades.Grade,
	Students.Marks
FROM
	Students
		INNER JOIN
			Grades
		ON
			Students.Marks BETWEEN Grades.Min_Mark AND Grades.Max_Mark
ORDER BY
	Grades.Grade DESC,
	Students.Name ASC,
	Students.Marks ASC
