open Css;

[@react.component]
let make = () => {
  let styles =
    style([
      width(pct(100.)),
      background(hex("C4C4C4")),
      height(px(200)),
      marginTop(px(400)),
    ]);

  <div className=styles />;
};
