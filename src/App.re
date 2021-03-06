open Css;

module Video = {
  [@bs.module "./components/Video.jsx"][@react.component]
  external make: (~name: string) => React.element = "default";
}

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
    <Container> <Main /> <Features /> <Video name="video" /> <CTA /> </Container>
    <Footer />
  </>;
};
