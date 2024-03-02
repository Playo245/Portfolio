import { useState, useEffect } from "react";
import SingleModule from "./single_module";
import AddModule from "./add_module";
import CohortModule from "./cohort_module";

function AllModule({ setComponent }) {
    const [modules, setModules] = useState(["Modules", "More Modules"]);
    const [cohorts, setCohorts] = useState(["Cohorts"]);
    const [isLoaded1, setIsLoaded1] = useState(false);
    const [isLoaded2, setIsLoaded2] = useState(false);

    const displayModules = () => {
        return modules.map((element, index) =>
            <li key={index}>
                <div className="card card-body mb-4 bg-secondary">
                    <h5>{element.full_name}</h5>
                    <ul>
                        <li>Code: {element.code}</li>
                        <li>
                            <button type="button" className="btn btn-dark view-button" onClick={() => { setComponent(<SingleModule module={element} setComponent={setComponent} />) }}>
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
        fetch("http://127.0.0.1:8000/api/module/")
            .then(response => response.json())
            .then(data => {
                setModules(data);
                setIsLoaded1(true);
            })
            .catch(error => console.log(error))

        fetch("http://127.0.0.1:8000/api/cohort/")
            .then(response => response.json())
            .then(data => {
                setCohorts(data);
                setIsLoaded2(true);
            })
            .catch(error => console.log(error))
    })

    const FilterCohort = () => {
        let options = cohorts.map((element, index) =>
            <option key={index} value={element.id}>{element.id} -- {element.name}</option>
        )

        return (
            <form onSubmit={getCohort} style={{ textAlign: "center", display: "flex" }}>
                <select id="cohortSelection" className="form-select">
                    {options}
                </select>
                <br />
                <button type="submit" className="btn btn-dark center" style={{ textAlign: "center"}}>
                    FILTER BY COHORT
                </button>
            </form>
        )
    }

    const getCohort = (e) => {
        e.preventDefault();
        setComponent(<CohortModule cohort={document.getElementById("cohortSelection").value} setComponent={setComponent} />)
    }

    if (!isLoaded1 || !isLoaded2) {
        return (
            <h1 className="mt-5">Loading</h1>
        )
    }

    return (
        <div style={{ textAlign: "center" }}>
            <br />
            <br />
            <div style={{ margin: '0 auto' }}>
                {FilterCohort()}
            </div>
            <br />
            <h1>Module List:</h1>
            <ul>
                {displayModules()}
            </ul>
            <button type="button" className="btn btn-dark mb-4" onClick={() => {setComponent(<AddModule setComponent={setComponent} />)}} style={{ textAlign: "center" }}>
                CREATE MODULE
            </button>
        </div>
    )
}
export default AllModule;