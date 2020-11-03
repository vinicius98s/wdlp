open Css;

[@react.component]
let make = () => {
  let wrapper =
    style([
      width(pct(100.)),
      display(flexBox),
      alignItems(center),
      justifyContent(center),
      selector(
        "div",
        [
          width(pct(40.)),
          height(px(450)),
          background(hex("C4C4C4")),
          media(
            "(max-width: 1050px)",
            [width(pct(100.)), height(px(300))],
          ),
        ],
      ),
    ]);

  <div className=wrapper> <div /> </div>;
};
