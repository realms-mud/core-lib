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
        "with arms and repairs. The captain is particular about "
        "maintenance, which suits me fine. A demanding customer "
        "makes for better craft.' @D@She picks the hammer back up. "
        "@S@'This week it was hinges, ploughshares, and a cracked "
        "wagon pin. Boring work keeps a village standing.'");
    addTopic("the smithy", "@D@Branna taps the anvil with her "
        "hammer. @S@'I make what I can here and repair what people "
        "bring me. If the metal is sound, most things can be put "
        "right.'");
    addTopic("good steel", "@S@'A good piece of steel is honest. "
        "It does not care who owns it, only whether it was made "
        "well and looked after.'");
    addTopic("repairs", "@D@Branna taps the workbench with the "
        "back of her hammer. @S@'I tell people what a repair will "
        "cost before I start. A farmer cannot feed a family on "
        "surprises, and a soldier cannot use a broken buckle.'");
    addTopic("the village", "@S@'I know the sound of every cart "
        "that uses this road. The western farmers have been hearing "
        "unfamiliar wheels after dark. That is not proof of theft, "
        "but I would check a loose axle before I let a rumor grow legs.'");

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
    addResponse("first conversation", "Can you repair my weapon?",
        "@S@'Set it on the bench. I will tell you what can be fixed "
        "before I take the hammer to it.'");
    addResponseTopic("first conversation", "Can you repair my weapon?",
        "repairs");
    addResponse("first conversation", "How are things in the village?",
        "@D@You ask what has changed in Branna's daily work.");
    addResponseTopic("first conversation",
        "How are things in the village?", "the village");

    addResponse("about branna", "What's got them worried?",
        "@D@Branna shrugs, the motion setting the tools on her belt "
        "jangling. @S@'I just make the steel. But the patrols have "
        "doubled, and Tormund's been asking about reinforcing the "
        "keep's gate. Draw your own conclusions.'");
    addResponse("about branna", "Do you trust the captain?",
        "@S@'I trust him to know his work. If he orders more spear "
        "points, I make them. I leave the reasons to the people "
        "who stand watch.'");
    addResponse("the smithy", "What makes steel reliable?",
        "@S@'Good material, steady heat, and patience. There is no "
        "trick that makes a rushed job sound.'");
    addResponseTopic("the smithy", "What makes steel reliable?",
        "good steel");
    addResponse("good steel", "Can anyone learn the craft?",
        "@S@'Anyone can learn the steps. Skill comes from practice "
        "and knowing when to start over.'");
    addResponse("repairs", "Can I help with a repair?",
        "@S@'You can learn by watching, if you have the patience "
        "to hold still and listen before reaching for a tool.'");
    addResponseTopic("repairs", "Can I help with a repair?", "good steel");
    addResponse("the village", "What have you heard?",
        "@D@Branna lowers her voice, though she keeps working. "
        "@S@'Harlan saw carts on the west track. I heard one of "
        "them had a damaged wheel. That is all I know, and I would "
        "rather ask than guess.'");
    addResponseTopic("the village", "What have you heard?", "repairs");
}
