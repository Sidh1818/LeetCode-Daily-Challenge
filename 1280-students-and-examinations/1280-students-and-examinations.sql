# Write your MySQL query statement below
select s.student_id , s.student_name , t.subject_name , count(e.subject_name) as attended_exams 
from students s
join subjects t
left join Examinations e on s.student_id = e.student_id and t.subject_name = e.subject_name
group by s.student_id,s.student_name,t.subject_name
order by s.student_id,t.subject_name;