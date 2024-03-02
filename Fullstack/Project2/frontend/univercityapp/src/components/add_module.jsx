import { useState, useEffect } from "react";
import SingleModule from "./single_module";
import { FindError, PrintError } from "../javascripts/checker";

function AddModule({ setComponent }) {
    const [error, setError] = useState([""]);
    const [delivered, setDelivered] = useState(1);
    const [cohorts, setCohorts] = useState(["Cohorts"]);
    const [isLoaded, setIsLoaded] = useState(false);

    const ShowForm = () => {
        return (
            <form id="moduleForm" onSubmit={validator} method="POST">
                <label htmlFor="code" className="form-label">Code:</label>
                <input type="Text" id="code" className="form-control" />
                {error.code}
                <label htmlFor="full_name" className="form-label">Full name:</label>
                <input type="Text" id="full_name" className="form-control" />
                {error.full_name}
                <label htmlFor="delivered_to" className="form-label">Deliver to:</label>
                <div id="selectCohorts">
                    {selectCohorts()}
                    {error.delivered_to}
                    <button type="button" className="btn btn-dark view-button" onClick={() => { setDelivered(delivered + 1) }}>
                        Add
                    </button>
                </div>
                <label htmlFor="ca_split" className="form-label">CA percentage:</label>
                <input type="Text" id="ca_split" className="form-control" />
                {error.ca_split}
                <button type="submit" className="btn btn-dark submit-button">
                    Submit
                </button>
            </form>
        )
    }

    const selectCohorts = () => {
        const selections = [];
        let options = cohorts.map((element, index) =>
            <option key={index} value={element.id}>{element.id} -- {element.name}</option>
        )
        for (var i = 0; i < delivered; i++) {
            selections.push(
                <select key={i} className="delivered_to form-select" style={{ marginBottom: "10px" }}>
                    {options}
                </select>
            )
        }
        return (
            <div>{selections}</div>
        )
    }

    const validator = async (e) => {
        e.preventDefault();
        const moduleForm = document.getElementById("moduleForm");
        const selections = document.getElementsByClassName("delivered_to");
        const delivered_to = [...selections].map((selection) => `http://127.0.0.1:8000/api/cohort/${selection.value}/`);
        const module = {
            code: moduleForm.code.value,
            full_name: moduleForm.full_name.value,
            delivered_to: delivered_to.sort(),
            ca_split: parseInt(moduleForm.ca_split.value),
        };
      
        try {
            const response = await fetch("http://127.0.0.1:8000/api/module/", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify(module),
            });
            const data = await response.json();
            console.log("Success:", data);
            if (!FindError(module, data)) {
                setError(PrintError(data));
            } else {
                setComponent(<SingleModule module={data} setComponent={setComponent} />);
            }
        }
        catch (error) {
          console.error(error);
        }
      };
      

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
export default AddModule;