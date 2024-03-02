import { useState, useEffect } from "react";
import SingleCohort from "./single_cohort";
import { FindError, PrintError } from "../javascripts/checker";

function AddCohort({ shortcode, setComponent }) {
    const [error, setError] = useState([""]);
    const [degrees, setDegrees] = useState(["Degree"]);
    const [isLoaded, setIsLoaded] = useState(false);

    const ShowForm = () => {
        return (
            <form id="cohortForm" onSubmit={handleSubmit} method="POST">
                <label htmlFor="id" className="form-label">ID:</label>
                <input type="Text" id="id" className="form-control" />
                {error.id}
                <label htmlFor="degree" className="form-label">Degree:</label>
                <select id="degree" className="form-select" defaultValue={shortcode}>
                    {pickDegree()}
                </select>
                {error.degree}
                <label htmlFor="year" className="form-label">Year:</label>
                <input type="Text" id="year" className="form-control" />
                {error.year}
                <button type="submit" className="btn btn-dark submit-button">
                    Submit
                </button>
            </form>
        )
    }

    const pickDegree = () => {
        return degrees.map((element, index) =>
            <option key={index} value={element.shortcode}>{element.shortcode} -- {element.full_name}</option>
        )
    }

    const handleSubmit = async (e) => {
        e.preventDefault();
        const cohortForm = document.getElementById("cohortForm");
        const cohort = {
            id: cohortForm.id.value,
            year: parseInt(cohortForm.year.value),
            degree: `http://127.0.0.1:8000/api/degree/${cohortForm.degree.value}/`,
        };
    
        try {
            const response = await fetch("http://127.0.0.1:8000/api/cohort/", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify(cohort),
            });
            const data = await response.json();
            console.log("Success:", data);
            if (!FindError(cohort, data)) {
                setError(PrintError(data));
            } else {
                setComponent(<SingleCohort cohort={data} setComponent={setComponent} />);
            }
        } catch (error) {
            console.error(error);
        }
    };

    useEffect(() => {
        fetch("http://127.0.0.1:8000/api/degree/")
            .then(response => response.json())
            .then(data => {
                setDegrees(data);
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
export default AddCohort;