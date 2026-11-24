//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Mira dries a cup with a "
        "well-used cloth and nudges the warm side of the hearth "
        "toward you. @S@'Sit if you mean to talk. If you mean to "
        "leave again in a hurry, take the stool by the door; the "
        "floorboards there do not complain.'");
    addTopic("the inn", "@S@'The Windward was a charcoal shed when "
        "I came here. My late partner and I put up the roof one "
        "summer, then spent three winters learning where the rain "
        "found its way in. The west wall still leaks in a hard "
        "storm. I keep a bucket there and call it tradition.'");
    addTopic("the food", "@D@She checks a pot without lifting the "
        "lid. @S@'Root stew today, barley bread if the mill cart "
        "came through. I do not promise a menu. I promise you will "
        "know what went into the bowl.'");
    addTopic("the stable", "@S@'The yard has room for two wagons "
        "and four tired horses. I used to leave the water checks "
        "to the drovers; now I do them myself. A horse that drinks too "
        "fast after a climb needs a minute before you saddle it.'");
    addTopic("the road", "@S@'The southern road brings mail and "
        "the northern road brings stories. Both are late in bad "
        "weather. If the beacon is dark, ask the outpost before "
        "you decide the quiet means there is no trouble.'");
    addTopic("your old partner", "@D@Mira's smile softens at the "
        "edge. @S@'Teren could repair anything except his own "
        "sleeping habits. He went out to check the roof in a "
        "winter gale and came back with a broken ankle. He lived "
        "long enough to teach me the business. I still set his "
        "mug on the shelf, not the table.'");

    addResponse("first conversation", "Do you have a room?",
        "@D@Mira hooks a thumb toward the narrow stairs. "
        "@S@'The loft is dry tonight. Two beds, a chest with a "
        "stiff latch, and a window that shows more sky than road.'");
    addResponseTopic("first conversation", "Do you have a room?",
        "the inn");
    addResponse("the inn", "Why did you stay so far from town?",
        "@D@She wipes a ring of moisture from the counter. "
        "@S@'Because travelers needed a roof here, and because "
        "Teren liked a horizon he could see. I stayed after he "
        "could no longer climb the stairs.'");
    addResponse("first conversation", "What is in the pot?",
        "@D@Mira lifts the lid just enough to check the stew. "
        "@S@'Barley, turnip, onion, and a little smoked fish if "
        "the tide has been kind. I will tell you if the recipe "
        "changes.'");
    addResponseTopic("first conversation", "What is in the pot?",
        "the food");
    addResponse("first conversation", "Can I stable a horse?",
        "@D@She nods toward the stable yard. "
        "@S@'If it is your horse, yes. Water first, then feed. "
        "If it belongs to someone else, ask them before you "
        "borrow a stall.'");
    addResponseTopic("first conversation", "Can I stable a horse?",
        "the stable");
    addResponse("the stable", "Who taught you to care for horses?",
        "@D@Mira folds the cloth over one shoulder. "
        "@S@'A patient drover who could tell a pulled shoe from "
        "the sound of one step on stone.'");
    addResponse("first conversation", "What do travelers say about the road?",
        "@D@She sets the cup upside down on the shelf. "
        "@S@'That depends on the weather and how much they paid "
        "for their boots. Ask Nerys for the warning; ask me for "
        "the gossip.'");
    addResponseTopic("first conversation",
        "What do travelers say about the road?", "the road");
    addResponse("the road", "What gossip have you heard?",
        "@D@Mira lowers her voice and glances toward the window. "
        "@S@'A coach went missing on the inland shelf. The people "
        "who were aboard matter more than the silver in the box.'");
    addResponse("your old partner", "Do you still miss him?",
        "@D@She sets the cup down carefully and lets her fingers "
        "rest on its handle. @S@'Every time the "
        "west wall leaks. He would have blamed the roof before "
        "the weather.'");
}
