import { useState, useEffect } from "react";
import SingleStudent from "./single_student";
import AddStudent from "./add_student";

function SingleCohort({ cohort, setComponent }) {
    const [isLoaded, setIsLoaded] = useState(false);
    const [students, setStudents] = useState([""]);

    const ShowCohort = () => {
        return (
            <div>
                <h1>{cohort.name}</h1>
                <br />
                <h5>ID: {cohort.id}</h5>
                <h5>Year: {cohort.year}</h5><br />
                <h4>Student List:
                    
                </h4>
                <ul className="sublist">
                    {ShowStudents()}
                </ul>
                <button type="button" className="btn btn-dark mb-4" onClick={() => {setComponent(<AddStudent cohortID={cohort.id} setComponent={setComponent} />)}} style={{ textAlign: "center"}}>
                    ADD STUDENT
                </button>
            </div>
        )
    }

    const ShowStudents = () => {
        return students.map((element, index) =>
            <li key={index}>
                <div className="card card-body mb-4 bg-secondary">
                    <ul>
                        <li key="student_id">Student ID: {element.student_id}</li>
                        <li key="first_name">First Name: {element.first_name}</li>
                        <li key="last_name">Last Name: {element.last_name}</li>
                        <li>
                            <button type="button" className="btn btn-dark view-button" onClick={() => { setComponent(<SingleStudent student={element} setComponent={setComponent} />) }}>
                                See More
                            </button>
                        </li>
                    </ul>
                </div>
                <br />
            </li>
        )
    }

    useEffect(() => {
        fetch("http://127.0.0.1:8000/api/student/?cohort=" + cohort.id)
            .then(response => response.json())
            .then(data => {
                setStudents(data);
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
            {ShowCohort()}
        </div>
    )
}

export default SingleCohort;