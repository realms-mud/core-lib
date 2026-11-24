//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Ithra turns from the drying rack "
        "and says, @S@'I keep this old shelter because the trail still "
        "needs watching. The road goes west to Hrondil; the forest path "
        "south leads back toward Tol-Dhurath.'");
    addTopic("remedies", "@D@Ithra sorts a few tied bundles and says, "
        "@S@'Willow bark for pain, feverfew for a stubborn chill. I sell "
        "what I can dry here, but I keep no cure for a wound you let "
        "fester.'");
    addTopic("road", "@D@Ithra taps the ridge on a hand-drawn map and "
        "says, @S@'The ford is safe in ordinary weather. After hard rain, "
        "stay on the western road and follow the old markers.'");

    addResponse("first conversation", "What do you trade?",
        "@D@You ask Ithra about the bundles on the rack.");
    addResponseTopic("first conversation", "What do you trade?",
        "remedies");
    addResponse("first conversation", "Where does this road lead?",
        "@D@You ask Ithra to point out the route.");
    addResponseTopic("first conversation", "Where does this road lead?",
        "road");
}
