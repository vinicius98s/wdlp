GlobalStyles.add();

let root = ReactDOM.querySelector("#root");

switch (root) {
| Some(el) => ReactDOM.render(<App />, el)
| None => Js.log("root not found")
};
