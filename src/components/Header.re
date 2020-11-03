open Css;
open Theme;

module Bubble = {
  let styles =
    style([
      position(absolute),
      background(Colors.blue(`primary)),
      width(px(245)),
      height(px(256)),
      borderRadius(pct(50.)),
      right(pct(-28.)),
      top(pct(-156.)),
      media("(min-width: 375px)", [width(vw(75.)), right(pct(-30.))]),
      media("(min-width: 460px)", [width(vw(65.))]),
      media("(min-width: 700px)", [width(vw(55.))]),
      media("(min-width: 1050px)", [width(pct(46.)), top(pct(-150.))]),
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
  let logo = style([marginLeft(rem(1.))]);
  let iconsWrapper = style([display(flexBox), zIndex(1)]);
  let header =
    style([
      height(px(100)),
      width(pct(100.)),
      display(flexBox),
      justifyContent(spaceBetween),
      alignItems(center),
      position(relative),
      color(Colors.white),
      overflow(hidden),
      paddingBottom(rem(0.6)),
    ]);

  <header className=header>
    <img
      width="160"
      height="68"
      className=logo
      src="/assets/logo.png"
      alt="WeDeal"
    />
    <Bubble />
    <div className=iconsWrapper>
      <img
        width="30"
        height="30"
        className=icon
        src="/assets/icons/facebook.png"
        alt="Facebook"
      />
      <img
        width="30"
        height="30"
        className=icon
        src="/assets/icons/instagram.png"
        alt="Instagram"
      />
      <img
        width="30"
        height="30"
        className=lastIcon
        src="/assets/icons/linkedin.png"
        alt="Linkedin"
      />
    </div>
  </header>;
};
