open Css;
open Theme;

module Feat = {
  [@react.component]
  let make = (~icon, ~text, ~styles=?) => {
    let iconSrc = "/assets/icons/" ++ icon ++ ".png";
    let description =
      style([
        color(Colors.white),
        fontWeight(`num(700)),
        fontSize(px(13)),
        maxWidth(px(105)),
        textAlign(center),
        marginTop(px(12)),
      ]);

    let wrapper =
      style([display(flexBox), alignItems(center), flexDirection(column)]);

    let additionalStyles =
      switch (styles) {
      | Some(s) => s
      | None => ""
      };

    <div className={Css.merge([wrapper, additionalStyles])}>
      <img src=iconSrc alt="" width="50" height="50" />
      <p className=description> text->React.string </p>
    </div>;
  };
};

[@react.component]
let make = () => {
  let container =
    style([
      display(flexBox),
      background(Colors.blue(`darker)),
      width(vw(100.)),
      height(px(800)),
      margin2(~h=px(-20), ~v=px(-250)),
      transform(skewY(deg(-10.))),
      alignItems(center),
      justifyContent(center),
      paddingTop(px(100)),
    ]);

  let wrapper =
    style([
      transform(skewY(deg(10.))),
      display(flexBox),
      flexWrap(wrap),
      alignItems(center),
      justifyContent(center),
    ]);

  let iconMq =
    style([
      media("(min-width: 345px)", [margin2(~v=px(10), ~h=px(20))]),
    ]);

  let screensImg =
    style([
      zIndex(1),
      width(pct(100.)),
      marginTop(px(80)),
      position(absolute),
      left(zero),
    ]);

  <>
    <div className=container>
      <div className=wrapper>
        <Feat
          styles={Css.merge([
            style([marginRight(px(30)), marginBottom(px(40))]),
            iconMq,
          ])}
          icon="book"
          text={j|Expanda sua experiência e portfólio|j}
        />
        <Feat
          styles={Css.merge([style([marginBottom(px(40))]), iconMq])}
          icon="person"
          text={j|Conquiste novos clientes|j}
        />
        <Feat styles=iconMq icon="idea" text={j|Tire suas ideias do papel|j} />
        <Feat styles=iconMq icon="boss" text={j|Seja o seu próprio chefe|j} />
        <Feat
          styles=iconMq
          icon="money"
          text={j|Invista em projetos inovadores|j}
        />
      </div>
    </div>
    <img className=screensImg src="/assets/wedeal-screens.png" alt="" />
  </>;
};
