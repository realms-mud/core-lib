//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Ryneth sets her pack "
        "down for a moment. @S@'I have walked since morning. "
        "A place to sit is enough for now.'");
    addTopic("inn", "@S@'I am looking for a modest meal and "
        "a safe place for the night. I do not need more than that.'");
    addResponse("first conversation", "Are you looking for a room?",
        "@D@She looks toward the inn's door.");
    addResponseTopic("first conversation", "Are you looking for "
        "a room?", "inn");
}
