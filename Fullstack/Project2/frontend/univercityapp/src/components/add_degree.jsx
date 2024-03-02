import { useState } from "react";
import SingleDegree from "./single_degree";
import {FindError, PrintError} from "../javascripts/checker";

function AddDegree({setComponent}) {
    const [error, setError] = useState([""]);

    const ShowForm = () =>{
        return (
            <div>
                <form id="degreeForm" onSubmit={validator}>
                    <label htmlFor="full_name" className="form-label">Full name:</label>
                    <input type="Text" id="full_name" className="form-control"/>
                    {error.full_name}
                    <label htmlFor="shortcode" className="form-label">Short code:</label>
                    <input type="Text" id="shortcode" className="form-control"/>
                    {error.shortcode}
                    <button type="submit" className="btn btn-dark submit-button">Submit</button>
                </form>
            </div>
        )
    }

    const validator = async (e) => {
        e.preventDefault();
        const degreeForm = document.getElementById("degreeForm");
        const degree = {
            shortcode: degreeForm.shortcode.value,
            full_name: degreeForm.full_name.value,
        };
      
        try {
            const response = await fetch("http://127.0.0.1:8000/api/degree/", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify(degree),
            });
            const data = await response.json();
            console.log("Success:", data);
            if (!FindError(degree, data)) {
                setError(PrintError(data));
            } else {
                setComponent(<SingleDegree degree={data} setComponent={setComponent} />);
            }
        } catch (error) {
            console.error(error);
        }
    };

    return (
        <div className="form-page">
            {ShowForm()}
        </div>
    )
}
export default AddDegree;
