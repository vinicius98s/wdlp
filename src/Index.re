Css.(
  global("*", [
    boxSizing(borderBox),
    padding(px(0)),
    margin(px(0)),
  ])
)

let root = ReactDOM.querySelector("#root");

switch(root) {
  | Some(el) => ReactDOM.render(<App />, el)
  | None => Js.log("root not found")
}

