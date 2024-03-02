import 'bootstrap/dist/css/bootstrap.css';
import './App.css';
import logo from './images/logo.png';
import { useState, useEffect } from 'react';
import Homepage from './components/homepage';
import DegreeAll from './components/all_degree';
import CohortAll from './components/all_cohort';
import ModuleAll from './components/all_module';
import Student from './components/student';

function App() {
    const [component, setComponent] = useState(null);

    useEffect(() => {
        setComponent(<Homepage setComponent={setComponent} />)
    }, []);

    const handleClick = (event, component) => {
        const buttons = document.querySelectorAll('.nav-link');
        buttons.forEach(button => button.classList.remove('active'));
        event.currentTarget.classList.add('active');
        setComponent(component);
    };

    return (
        <div className="App">
            <nav className="navbar navbar-expand-lg navbar-dark bg-dark fixed-top">
            <div className="container-fluid">
                <a className="navbar-brand" href="#/" onClick={event => handleClick(event, <Homepage setComponent={setComponent} />)}>
                    <img src={logo} alt="Logo" width="120" height="120" />
                </a>
                <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                <span className="navbar-toggler-icon"></span>
                </button>
                <div className="collapse navbar-collapse" id="navbarNav">
                    <ul className="navbar-nav justify-content-end">
                        <li className="nav-item">
                            <a id="degrees" className="nav-link" href="#/" onClick={event => handleClick(event, <DegreeAll setComponent={setComponent} />)}>Degrees</a>
                        </li>
                        <li className="nav-item">
                            <a id="cohorts" className="nav-link" href="#/" onClick={event => handleClick(event, <CohortAll setComponent={setComponent} />)}>Cohorts</a>
                        </li>
                        <li className="nav-item">
                            <a id="modules" className="nav-link" href="#/" onClick={event => handleClick(event, <ModuleAll setComponent={setComponent} />)}>Modules</a>
                        </li>
                        <li className="nav-item">
                            <a id="students" className="nav-link" href="#/" onClick={event => handleClick(event, <Student setComponent={setComponent} />)}>Students</a>
                        </li>
                    </ul>
                </div>
            </div>
            </nav>
            <div className="App-content container-fluid">
                {component}
            </div>
        </div>
    );
}
export default App;
