//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'The north road leads back "
        "toward the capital. The south road is open, but check the "
        "notice board before you travel.'");
    addTopic("outcast camp", "@S@'Some families keep to the western "
        "fields. If they have caused no harm, leave them in peace. "
        "If you have a specific concern, bring me facts.'");
    addResponse("first conversation", "Is the south road safe?",
        "@S@'It is watched near town. Farther out, the old caravan "
        "ground is a place to stay alert, not a reason to blame "
        "everyone who lives nearby.'");
    addResponseTopic("first conversation", "Is the south road safe?",
        "outcast camp");
}
