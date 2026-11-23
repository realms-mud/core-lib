//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Melach regards you from beneath "
        "the dark folds of his robe. @S@'Speak plainly. Justice has "
        "little use for performance.'");
    addTopic("the hall", "@S@'This house serves the law, not the "
        "ambition of any one ruler. The records must remain honest, "
        "even when honesty is dangerous.'");
    addTopic("judgment", "@S@'A judgment must rest on evidence and "
        "careful thought. Anger may point toward a wrong, but it "
        "cannot decide the answer.'");
    addTopic("advice", "@D@Melach's voice lowers. @S@'Do not let "
        "opposition make you into the thing you oppose. A just cause "
        "does not excuse cruelty.'");

    addResponse("first conversation", "What is this place?",
        "@S@'The Halls of Justice. Here, petitions are heard and "
        "the city's judgments are recorded.'");
    addResponseTopic("first conversation", "What is this place?",
        "the hall");
    addResponse("first conversation", "How should a judge decide?",
        "@S@'By evidence, restraint, and a willingness to hear "
        "what is inconvenient.'");
    addResponseTopic("first conversation",
        "How should a judge decide?", "judgment");
    addResponse("judgment", "What if the cause is righteous?",
        "@S@'Then take care that your means remain righteous too.'");
    addResponseTopic("judgment", "What if the cause is righteous?",
        "advice");
}
