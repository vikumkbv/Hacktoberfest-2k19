import Browser
import Html exposing (Html, h1, text)


main : Program () Model Msg
main =
    Browser.sandbox
        { init = init
        , update = update
        , view = view
        }


type alias Model =
    { message : String
    }


init : Model
init =
    { message = "Hello World!"
    }


type Msg
    = NoOp


update : Msg -> Model -> Model
update msg model =
    case msg of
        NoOp ->
            model


view : Model -> Html Msg
view model =
    h1 [] [ text model.message ]

