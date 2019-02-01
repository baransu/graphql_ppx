module MyQuery = [%graphql
  {|
  subscription {
    simpleSubscription {
      ...on Dog {
        name
      }
      ...on Human {
        name
      }
    }
  }
|}
];

Jest.(
  describe("Subscriptions", () => {
    open Expect;
    open! Expect.Operators;

    test("Printed query is a subscription", () => {
      let query = MyQuery.query;
      Js.log(query);
      expect(query |> Js.String.indexOf("subscription")) == 0;
    });

    test(
      "Apollo mode should not have __typename on top subscription object", () => {
      let typenameRegex = [%bs.re {|/__typename/g|}];
      MyQuery.query
      |> Js.String.match(typenameRegex)
      |> Belt.Option.map(_, Array.length)
      |> expect == Some(3);
    });
  })
);