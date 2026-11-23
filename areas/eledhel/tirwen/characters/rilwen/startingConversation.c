//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Rilwen sets down a small basket "
        "of windfalls. @S@'The orchard is worked by our household. "
        "Ask before taking fruit from the marked rows.'");
    addTopic("orchard", "@S@'The apple stands are tended, not common "
        "ground. We gather the fallen fruit after the pressing and "
        "leave the sound trees for the next season.'");
    addTopic("road", "@S@'The lane joins the King's Road just south "
        "of here. Rhaedhen is the nearest place to find a roof. "
        "The ford farther south is hard going after heavy rain.'");
    addTopic("flock", "@S@'Edran keeps the sheep at the upper fold. "
        "Close the gate behind you; the flock uses both sides of "
        "the pasture through the year.'");
    addResponse("first conversation", "May I gather apples here?",
        "@S@'Only the marked windfalls after harvest. The trees "
        "are a household crop.'");
    addResponseTopic("first conversation", "May I gather apples here?",
        "orchard");
    addResponse("first conversation", "Who keeps the sheep?",
        "@S@'Edran is at the upper fold. He knows which gates are "
        "open to the drovers.'");
    addResponseTopic("first conversation", "Who keeps the sheep?",
        "flock");
    addResponse("first conversation", "Where does this lane lead?",
        "@S@'South to the King's Road. Rhaedhen lies north along it.'");
    addResponseTopic("first conversation", "Where does this lane lead?",
        "road");
}
