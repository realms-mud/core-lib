//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Anwen watches the doorway "
        "for a moment before she answers. @S@'I am Anwen. If "
        "you came from the road, tell me whether the beacon "
        "is lit. I have been below long enough that every "
        "footstep sounds like the one that found me.'");
    addTopic("the coach", "@S@'I was the attendant, not the "
        "driver. The axle broke on the shelf, then men came "
        "out of the trees. One wanted the strongbox. One "
        "wanted the passenger list. I hid under the coach "
        "until the rain covered my tracks.'");
    addTopic("the cellar", "@D@She rubs the bandage above her "
        "wrist. @S@'Oren let me stay because the men below "
        "said they would leave if I kept quiet. He did not "
        "know they had taken my dispatch case. I will not "
        "leave while it is still here.'");
    addTopic("the outlaws", "@S@'They are not a troop. There "
        "are three who take orders and one who would rather "
        "walk away. They took food and letters. They have "
        "not harmed Oren's family, but that is not a promise "
        "they made to me.'");
    addTopic("your sister", "@D@Anwen turns the brass buckle "
        "at her collar. @S@'Talia is waiting at the southern "
        "post. She is twelve and thinks every delay is a "
        "story I will tell at supper. I need her to keep "
        "thinking that.'");
    addTopic("the dispatch", "@S@'The case has a blue cord "
        "around it. The papers inside list the coach's "
        "passengers and the next delivery. I do not know "
        "why someone wanted it more than the money.'");

    addResponse("first conversation", "How did you get here?",
        "@D@Anwen draws her shawl close and glances toward the hatch. "
        "@S@'Oren found me at the mill race at dawn. The "
        "outlaws brought the strongbox below and left me "
        "to make sure no one followed.'");
    addResponseTopic("first conversation", "How did you get here?",
        "the coach");
    addResponse("the coach", "Were the passengers hurt?",
        "@D@She pinches the bridge of her nose, searching her memory. "
        "@S@'One was bruised. The driver went south for help. "
        "I do not know where the other passenger went.'");
    addResponse("first conversation", "Why stay in the cellar?",
        "@D@Anwen keeps her voice low and watches the doorway. "
        "@S@'The dispatch case is there. If I go out alone, "
        "they can move it before anyone asks questions.'");
    addResponseTopic("first conversation", "Why stay in the cellar?",
        "the cellar");
    addResponse("first conversation", "Can I speak to the outlaws?",
        "@D@She leans closer, careful not to carry her voice below. "
        "@S@'One of them listens when Oren talks; the others "
        "follow his lead. Ask what they want before you draw "
        "a weapon. I cannot promise they will answer.'");
    addResponseTopic("first conversation",
        "Can I speak to the outlaws?", "the outlaws");
    addResponse("the outlaws", "Why would they leave?",
        "@D@Anwen folds her arms over the bandage at her wrist. "
        "@S@'They have food, but no safe place to sell it. "
        "If Hedran sees the dispatch and the sack tally, he "
        "can decide whether there is a way out that is not "
        "another ambush.'");
    addResponse("first conversation", "Who is Talia?",
        "@D@A small smile breaks through her worry. "
        "@S@'My younger sister. She is better at sums than I "
        "am and worse at waiting. I promised to bring her a "
        "blue ribbon from Minlach.'");
    addResponseTopic("first conversation", "Who is Talia?",
        "your sister");
    addResponse("the cellar", "What is in the dispatch case?",
        "@D@She taps the blue cord around her wrist. "
        "@S@'The names of the passengers, the cargo, and "
        "the dates of the next runs. Nothing magical. Just "
        "enough truth to ruin someone's plans.'");
    addResponseTopic("the cellar", "What is in the dispatch case?",
        "the dispatch");
    addResponse("the dispatch", "Will you return to the road?",
        "@D@Anwen straightens, as if she has already decided. "
        "@S@'If the case is safe and the outpost knows what "
        "happened. I am not going to run south and leave "
        "the next coach to meet the same men.'");
}
