//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Branna glances up from the "
        "anvil, hammer still in hand, and gives a curt nod. "
        "@S@'If you're here to gawk, the door's behind you. "
        "If you're here for steel, we can talk.'");
    addTopic("about branna", "@S@'I supply the keep's garrison "
        "with arms and repairs. Lord Edran's captain, Tormund, he's "
        "particular about his equipment - which suits me fine. A "
        "demanding customer makes for better craft.' @D@She picks "
        "the hammer back up. @S@'Lately they've been ordering more "
        "than usual, though. Extra spearheads, arrowheads by the "
        "bundle. Something's got them worried.'");

    addResponse("first conversation", "I'd like to see your wares.",
        "@D@She sets the hammer down and wipes her hands on her "
        "apron. @S@'Right then. Have a look - everything I make "
        "is honest work. No frills, but it'll keep you alive.' "
        "@D@She gestures toward the racks of weapons and tools. "
        "@S@'Just say `shop` when you're ready to deal.'");
    addResponse("first conversation", "Tell me about yourself.",
        "@S@'Not much to tell. My father was a smith, his father "
        "before him. I took to the hammer young and never put it "
        "down.' @D@She flexes a scarred hand. @S@'I make the best "
        "steel between here and the capital. Ask anyone.'");
    addResponseTopic("first conversation",
        "Tell me about yourself.", "about branna");

    addResponse("about branna", "What's got them worried?",
        "@D@Branna shrugs, the motion setting the tools on her belt "
        "jangling. @S@'I just make the steel. But the patrols have "
        "doubled, and Tormund's been asking about reinforcing the "
        "keep's gate. Draw your own conclusions.'");
}
