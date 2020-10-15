open Css;
open Theme;

module Bubble = {
  let styles =
    style([
      position(absolute),
      background(Colors.blue(`primary)),
      width(px(245)),
      height(px(256)),
      borderRadius(pct(50.0)),
      right(pct(-28.0)),
      top(pct(-156.0)),
    ]);

  [@react.component]
  let make = () => {
    <div className=styles />;
  };
};

[@react.component]
let make = () => {
  let getIconStyle = (~lastIcon=?, ()) => {
    let value =
      switch (lastIcon) {
      | Some(v) => v ? 0.6 : 0.3
      | None => 0.3
      };

    style([marginRight(rem(value))]);
  };

  let icon = getIconStyle();
  let lastIcon = getIconStyle(~lastIcon=true, ());
  let logo = style([marginLeft(rem(0.5))]);
  let iconsWrapper = style([display(flexBox), zIndex(1)]);
  let header =
    style([
      height(px(100)),
      width(vw(100.0)),
      display(flexBox),
      justifyContent(spaceBetween),
      alignItems(center),
      position(relative),
      color(Colors.white),
      overflow(hidden),
      paddingBottom(rem(0.6)),
    ]);

  <header className=header>
    <img className=logo src="/assets/logo.png" />
    <Bubble />
    <div className=iconsWrapper>
      <img className=icon src="/assets/icons/facebook.png" />
      <img className=icon src="/assets/icons/instagram.png" />
      <img className=lastIcon src="/assets/icons/linkedin.png" />
    </div>
  </header>;
};
