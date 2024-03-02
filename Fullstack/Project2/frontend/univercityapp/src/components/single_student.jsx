import { useState, useEffect } from "react";
import AddGrade from "./grade_student";

function SingleStudent({ student, setComponent }) {
    const [grades, setGrades] = useState([""]);
    const [isLoaded, setIsLoaded] = useState(false);

    const ShowStudent = () => {
        return (
            <ul style={{ paddingTop: "30px", fontSize: "23px" }}>
                <li>Cohort: {student.cohort.split("/")[5]}</li>
                <li>Student ID: {student.student_id}</li>
                <li>First Name: {student.first_name}</li>
                <li>Last Name: {student.last_name}</li>
                <li>Email: {student.email}</li><br />
                <li><h4>Grades:</h4>
                    <ul style={{ marginTop: "15px" }}>{ShowGrades()}</ul>
                </li>
                <br />
            </ul>
        )
    }

    const ShowGrades = () => {
        return grades.map((element, index) =>
            <li key={index}>
                <div className="card card-body mb-4 bg-secondary">
                    <h5>{element.module.split("/")[5]}</h5>
                    <br />
                    <ul style={{ paddingLeft: 5, marginTop: "-10px", fontSize: "18px" }}>
                        <li>CA Mark: {element.ca_mark}</li>
                        <li>Exam Mark: {element.exam_mark}</li>
                        <li>Total Grade: {element.total_grade}</li>
                    </ul>
                    <br />
                    <button type="button" className="btn btn-dark" onClick={() => {setComponent(<AddGrade setComponent={setComponent} grade_id={element.id} student={student} module={element.module} cohort={student.cohort} />)}} style={{ textAlign: "center"}}>
                        Set Student Grade
                    </button>
                </div><br />
            </li>
        )
    }

    useEffect(() => {
        fetch("http://127.0.0.1:8000/api/grade/?student=" + student.student_id)
            .then(response => response.json())
            .then(data => {
                setGrades(data);
                setIsLoaded(true);
            })
            .catch(error => console.log(error))
    })

    if (!isLoaded) {
        return (
            <h1 className="mt-5">Loading</h1>
        )
    }

    return (
        <div>
            {ShowStudent()}
        </div>
    )
}
export default SingleStudent;