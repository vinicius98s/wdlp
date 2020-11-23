open Css;
open Theme;

[@react.component]
let make = (~children, ~bgColor=?, ~styles=?) => {
  let backgroundColor =
    switch (bgColor) {
    | Some(color) => color
    | None => Colors.blue(`primary)
    };

  let additionalStyles =
    switch (styles) {
    | Some(style) => style
    | None => ""
    };

  let wrapper =
    style([
      background(backgroundColor),
      borderStyle(`none),
      color(Colors.white),
      borderRadius(px(5)),
      padding2(~v=px(12), ~h=px(5)),
      fontSize(px(32)),
      fontWeight(`num(900)),
      cursor(pointer),

      media("(max-width: 1020px)", [fontSize(px(13))]),
    ]);

  <button className={Css.merge([wrapper, additionalStyles])}>
    children
  </button>;
};
