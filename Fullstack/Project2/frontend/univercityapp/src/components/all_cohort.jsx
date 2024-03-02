import { useState, useEffect } from "react";
import SingleCohort from "./single_cohort";
import AddCohort from "./add_cohort";

function AllCohort({ setComponent }) {
    const [cohorts, setCohorts] = useState(["Cohorts", "More Cohorts"]);
    const [isLoaded, setIsLoaded] = useState(false);
    const ShowCohorts = () => {
        return cohorts.map((element, index) =>
            <li key={index}>
                <div className="card card-body mb-4 bg-secondary">
                    <h5>{element.name}</h5>
                    <ul>
                        <li key="year">Year: {element.year}</li>
                        <li key="id">ID: {element.id}</li>
                        <li>
                            <button type="button" className="btn btn-dark view-button" onClick={() => { setComponent(<SingleCohort cohort={element} setComponent={setComponent} />) }
                            }>See More</button>
                        </li>
                    </ul>
                </div>
                <br />
            </li>
        )
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
        <div style={{ textAlign: "center" }}>
            <br />
            <h1>Cohort List</h1>
            <br />
            <ul>
                {ShowCohorts()}
            </ul>
            <button type="button" className="btn btn-dark mb-5" onClick={() => {setComponent(<AddCohort setComponent={setComponent} />)}}>
                    CREATE COHORT
            </button>
        </div>
    )
}
export default AllCohort;