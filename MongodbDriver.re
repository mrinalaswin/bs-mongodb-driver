[@bs.deriving abstract]
type options = {
  [@bs.optional]
  useNewUrlParser: bool,
  [@bs.optional]
  useUnifiedTopology: bool,
};

[@bs.deriving abstract]
type filter = {
  [@bs.optional]
  filter: string,
};

[@bs.new] [@bs.module "mongodb"]
external make: (~uri: string, ~options: options) => 'client = "MongoClient";

[@bs.send]
external connect: ('self, Js.Nullable.t('error) => unit) => unit = "connect";
[@bs.send] external db: ('self, ~dbName: string) => 'db = "db";
[@bs.send]
external collection: ('self, ~collectionName: string) => 'collection =
  "collection";
[@bs.send] external close: 'self => unit = "close";
[@bs.send] external find: ('self, ~filter: filter) => 'documents' = "find";
