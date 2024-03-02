import { useState, useEffect } from "react";
import SingleDegree from "./single_degree";
import AddDegree from "./add_degree";

const displayDegrees = (degrees, setComponent) => {
    return degrees.map((element, index) => (
        <li key={index}>
            <div className="card card-body mb-4 bg-secondary">
                <h5>{element.shortcode}</h5>
                <p>{element.full_name}</p>
                <button type="button"className="btn btn-dark view-button" onClick={() => {setComponent(<SingleDegree degree={element} setComponent={setComponent} />);}}>
                    See More
                </button>
            </div>
        </li>
    ));
};

function AllDegree({ setComponent }) {
    const [degrees, setDegrees] = useState([]);
    const [isLoaded, setIsLoaded] = useState(false);

    useEffect(() => {
        fetch("http://127.0.0.1:8000/api/degree/")
            .then((response) => response.json())
            .then((data) => {
            setDegrees(data);
            setIsLoaded(true);
        })
        .catch((error) => console.log(error));
    }, []);

    if (!isLoaded) {
        return (
            <h1 className="mt-5">Loading</h1>
        )
    }

    return (
        <div style={{ textAlign: "center" }}>
            <br />
            <h1>Degree List</h1>
            <br />
            <ul>{displayDegrees(degrees, setComponent)}</ul>
            <button type="button" className="btn btn-dark mb-5" onClick={() => {setComponent(<AddDegree setComponent={setComponent} />);}}style={{ textAlign: "center"}}>
                CREATE DEGREE
            </button>
        </div>
    );
}

export default AllDegree;
