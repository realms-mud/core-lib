//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Rillan checks the patched "
        "elbow of her coat. @S@'It still keeps the rain off. That is "
        "all I need from it.'");
    addTopic("office clothes", "@S@'I copy accounts at the lower "
        "storehouse. The ink stains wash out, but the chair catches "
        "the same sleeve every day.'");
    addResponse("first conversation", "Why is the coat patched?",
        "@D@She smooths the cloth over her forearm.");
    addResponseTopic("first conversation", "Why is the coat patched?",
        "office clothes");
}
