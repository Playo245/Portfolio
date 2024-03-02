import { useState, useEffect } from "react";
import SingleStudent from "./single_student";
import { FindError, PrintError } from "../javascripts/checker";

function AddStudent({ cohortID, setComponent }) {
    const [error, setError] = useState([""]);
    const [cohorts, setCohorts] = useState(["Cohorts"]);
    const [isLoaded, setIsLoaded] = useState(false);

    const ShowForm = () => {
        return (
            <form id="studentForm" onSubmit={validator} method="POST">
                <label htmlFor="first_name" className="form-label">First name:</label>
                <input type="Text" id="first_name" className="form-control" />
                {error.first_name}
                <label htmlFor="last_name" className="form-label">Last name:</label>
                <input type="Text" id="last_name" className="form-control" />
                {error.last_name}
                <label htmlFor="cohort" className="form-label">Cohort:</label>
                <select id="cohort" className="form-select" defaultValue={cohortID}>
                    {selectCohort()}
                </select>
                {error.cohort}
                <button type="submit" className="btn btn-dark submit-button">Submit</button>
            </form>
        )
    }

    const selectCohort = () => {
        return cohorts.map((element, index) =>
            <option key={index} value={element.id}>{element.id} -- {element.name}</option>
        )
    }

    const createGrades = (student) => {
        /* Create Grade instances for each module */
        fetch("http://127.0.0.1:8000/api/module/?delivered_to=" + student.cohort.split("/")[5])
            .then(response => response.json())
            .then(data => {
                for (var module of data) {
                    var grade = {
                        "module": "http://127.0.0.1:8000/api/module/" + module.code + "/",
                        "cohort": student.cohort,
                        "student": "http://127.0.0.1:8000/api/student/" + student.student_id + "/",
                    }
                    fetch("http://127.0.0.1:8000/api/grade/", {
                        method: "POST",
                        headers: {
                            "Content-Type": "application/json",
                        },
                        body: JSON.stringify(grade),
                    })
                        .then(response => response.json())
                        .then(data => {
                            console.log("Success:", data);
                        })
                        .catch(error => console.log(error))
                }
            })
            .catch(error => console.log(error))
    }

    const validator = async (e) => {
        e.preventDefault();
        let studentForm = document.getElementById("studentForm");
        var student = {
            "first_name": studentForm.first_name.value,
            "last_name": studentForm.last_name.value,
            "cohort": "http://127.0.0.1:8000/api/cohort/" + studentForm.cohort.value + "/",
        }
    
        try {
            const response = await fetch("http://127.0.0.1:8000/api/student/", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify(student),
            });
    
            const data = await response.json();
    
            console.log("Success:", data);
            if (!FindError(student, data)) {
                setError(PrintError(data));
            } else {
                student.student_id = data.student_id;
                await createGrades(student);
                setComponent(<SingleStudent setComponent={setComponent} student={data} />);
            }
        } catch (error) {
            console.log(error);
        }
    }

    useEffect(() => {
        fetch("http://127.0.0.1:8000/api/cohort/")
            .then(response => response.json())
            .then(data => {
                setCohorts(data);
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
        <div className="form-page">
            {ShowForm()}
        </div>
    )
}
export default AddStudent;