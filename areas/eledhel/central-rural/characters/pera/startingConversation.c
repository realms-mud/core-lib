//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Pera arranges a basket of apples "
        "and gives you a quick, appraising look.");
    addTopic("the west road", "@S@'The west road is busy in the morning. "
        "Farm carts head for the gate, and the hunters come back before "
        "dark. The city patrols know the safe tracks.'");
    addTopic("the harvest", "@S@'The farms close to the walls bring in "
        "apples, onions, and greens. Farther west the fields thin out "
        "and the woods take over.'");
    addTopic("local gardens", "@D@Pera turns an empty basket toward "
        "the common beds. @S@'North of my stand are marked kitchen "
        "gardens and roots. The orchard is west, and the spring "
        "hollow north of that has raspberries when they are ripe.'");
    addTopic("farm neighbors", "@S@'South from the cart crossing "
        "is the mill lane. Torven works inside the mill; Nessa "
        "sells stores in the granary west of the public roots. "
        "Idel keeps the barn north of the threshing yard.'");
    addTopic("the northern road", "@S@'Travelers come down from the "
        "coast with salt fish and news. Minlach is a long ride north; "
        "ask the gate patrol before you set out.'");
    addTopic("the tree line", "@S@'The woods begin where the last "
        "fields end. I do not follow the game trails myself, but the "
        "hunters know which ones are safe and which ones to avoid.'");
    addTopic("the city market", "@S@'I bring the best of the nearby "
        "farms to the city. The market sellers farther in have more "
        "variety, but my produce has not spent a day on the road.'");
    addTopic("market stores", "@S@'We keep root vegetables in cool "
        "cellars and dry what will last. It takes planning to feed "
        "the city when the roads are slow.'");
    addTopic("woodland reports", "@S@'The hunters have seen tracks "
        "they cannot name. That is all I know. They keep to the "
        "marked trails and tell the patrol when something changes.'");

    addResponse("first conversation", "How is the road today?",
        "@S@'Clear to the last farm. Beyond that, keep to the marked "
        "track and watch the tree line.'");
    addResponseTopic("first conversation", "How is the road today?",
        "the west road");
    addResponse("the west road", "What do you sell?",
        "@S@'Apples, onions, greens, and whatever the farms can spare.'");
    addResponseTopic("the west road", "What do you sell?",
        "the harvest");
    addResponse("first conversation", "Where do the northern carts come from?",
        "@S@'Most come down from Minlach. Some carry fish, some carry "
        "news, and all of them want a hot meal.'");
    addResponseTopic("first conversation",
        "Where do the northern carts come from?", "the northern road");
    addResponse("the west road", "Are there dangers in the woods?",
        "@S@'Nothing I can name for certain. The hunters have found "
        "tracks they did not recognize, though, and they come home "
        "before dusk now.'");
    addResponseTopic("the west road", "Are there dangers in the woods?",
        "the tree line");
    addResponse("the tree line", "Do you sell anything for the road?",
        "@S@'Apples travel well. Take a few for the walk, and mind "
        "the ones that bruise.'");
    addResponse("the harvest", "Why bring it here yourself?",
        "@S@'Fresh goods fetch a fair price, and I like to know "
        "what reaches the city. A market is only as good as the "
        "farms that feed it.'");
    addResponseTopic("the harvest", "Why bring it here yourself?",
        "the city market");
    addResponse("the harvest", "Where can I gather a little food?",
        "@S@'At the marked common beds, in season. Not every "
        "field beside the road is open to gleaning.'");
    addResponseTopic("the harvest", "Where can I gather a little food?",
        "local gardens");
    addResponse("local gardens", "Can I buy food instead?",
        "@S@'Use my provision counter. There are stored roots "
        "as well as fruit; you need not wait for a berry season.'");
    addResponse("the city market", "Who supplies your stand?",
        "@D@She checks a label before answering. @S@'The "
        "households here, not a caravan from the far north.'");
    addResponseTopic("the city market", "Who supplies your stand?",
        "farm neighbors");
    addResponse("the northern road", "Do you know the way to Minlach?",
        "@S@'Follow the north road and ask at the gate before you "
        "leave the settled farms. The patrol can tell you which "
        "stretch is best traveled.'");
    addResponse("the harvest", "How does the city manage in winter?",
        "@S@'We store what keeps and bring fresh goods when the "
        "roads allow. The market sellers know which families need "
        "help when supplies run low.'");
    addResponseTopic("the harvest", "How does the city manage in winter?",
        "market stores");
    addResponse("market stores", "Can I carry food to Minlach?",
        "@S@'Hard fruit and roots travel well. Ask the harbor "
        "merchants what is scarce before you buy a large load.'");
    addResponseTopic("market stores", "Can I carry food to Minlach?",
        "the northern road");
    addResponse("the tree line", "What did the hunters find?",
        "@S@'Only tracks they could not identify. They did not "
        "follow them, and neither should you. Tell the patrol if "
        "you see any sign yourself.'");
    addResponseTopic("the tree line", "What did the hunters find?",
        "woodland reports");
    addResponse("woodland reports", "Do you know what made them?",
        "@S@'No. I will not make a guess sound like a warning. "
        "The hunters and patrol are better placed to find out.'");
    addResponseTopic("woodland reports",
        "Do you know what made them?", "the west road");
}
