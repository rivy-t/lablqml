(* Generated at 2013-03-27 13:45:00.159874 *)

open QmlContext


class virtual base_DataItem cppobj = object(self)
  initializer set_caml_object cppobj self
  method handler = cppobj
  method virtual name: unit-> string
  method virtual sort: unit-> string
end

external create_DataItem: unit -> 'a = "caml_create_DataItem"
