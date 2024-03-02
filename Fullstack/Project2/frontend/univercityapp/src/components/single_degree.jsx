import { useState, useEffect } from "react";
import SingleCohort from "./single_cohort";
import AddCohort from "./add_cohort";

function SingleDegree({ degree, setComponent }) {
    const [cohorts, setCohorts] = useState([]);
    const [isLoaded, setIsLoaded] = useState(false);

    const ShowCohorts = () => {
        return cohorts.map((cohort) => (
            <li key={cohort.id}>
                <div className="card card-body mb-4 bg-secondary">
                    <h5>{cohort.name}</h5>
                    <ul>
                        <li key="id">ID: {cohort.id}</li>
                        <li key="year">Year: {cohort.year}</li>
                        <li>
                            <button type="button" className="btn btn-dark view-button" onClick={() => setComponent(<SingleCohort cohort={cohort} setComponent={setComponent} />)}>
                                See More
                            </button>
                        </li>
                    </ul>
                </div>
            <br />
        </li>
        ));
    };

    const displayDegree = () => {
        return (
            <div>
                <h1>{degree.shortcode}</h1>
                <h5>{degree.full_name}</h5>
                <br />
                <h1>Cohorts</h1>
                <ul>
                    {ShowCohorts()}
                </ul>
                <button type="button" className="btn btn-dark mb-5" onClick={() => setComponent(<AddCohort shortcode={degree.shortcode} setComponent={setComponent}/>)}style={{ textAlign: "center"}}>
                    CREATE COHORT
                </button>
            </div>
        );
    };

    useEffect(() => {
        fetch(`http://127.0.0.1:8000/api/cohort/?degree=${degree.shortcode}`)
            .then((response) => response.json())
            .then((data) => {
                setCohorts(data);
                setIsLoaded(true);
            })
        .catch((error) => console.log(error));
    }, [degree.shortcode]);

    if (!isLoaded) {
        <h1 className="mt-5">Loading</h1>
    }

    return <div>{displayDegree()}</div>;
}

export default SingleDegree;
