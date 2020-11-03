open Css;

module Container = {
  let styles =
    style([
      width(pct(100.)),
      marginTop(px(50)),
      padding4(~top=zero, ~right=px(20), ~bottom=zero, ~left=px(20)),
    ]);

  [@react.component]
  let make = (~children) => {
    <div className=styles> children </div>;
  };
};

[@react.component]
let make = () => {
  <>
    <Header />
    <Container> <Main /> <Features /> <Video /> <CTA /> </Container>
  </>;
};
