import { useState, useEffect } from "react";
import AllModule from "./all_module";
import SingleModule from "./single_module";
import AddModule from "./add_module";

function CohortModule({ cohort, setComponent }) {
    const [modules, setModules] = useState(["Modules"]);
    const [isLoaded, setIsLoaded] = useState(false);

    const displayModules = () => {
        return modules.map((element, index) =>
            <li key={index}>
                <div className="card card-body mb-4 bg-secondary">
                    <h5>{element.full_name}</h5>
                    <ul>
                        <li>Code: {element.code}</li>
                        <br />
                        <li>
                            <button type="button" className="btn btn-dark view-button" onClick={() => { setComponent(<SingleModule module={element} setComponent={setComponent} />) }}>
                                See more
                            </button>
                        </li>
                    </ul>
                </div>
            </li>
        )
    }

    useEffect(() => {
        fetch("http://127.0.0.1:8000/api/module/?delivered_to=" + cohort)
            .then(response => response.json())
            .then(data => {
                setModules(data);
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
            <h2>{cohort} Module List:</h2>
            <button type="button" className="btn btn-dark align-top" onClick={() => {setComponent(<AllModule setComponent={setComponent} />)}} style={{ textAlign: "center"}}>
                Clear Filter
            </button>
            {displayModules()}
            <button type="button" className="btn btn-dark mb-4" onClick={() => {setComponent(<AddModule setComponent={setComponent} />)}} style={{ textAlign: "center" }}>
                Create Module
            </button>
        </div>
    )
}
export default CohortModule;