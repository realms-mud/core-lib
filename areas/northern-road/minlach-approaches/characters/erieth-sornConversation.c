//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Erieth trims the shrine "
        "wick with a pair of brass shears. @S@'The road carries "
        "many kinds of traveler. You need not tell me which "
        "kind you are. You can sit a moment if you need to.'");
    addTopic("the shrine", "@S@'The niche is for anyone who "
        "wants a quiet pause before the gate. The offerings "
        "belong to no keeper. Leave them where another traveler "
        "can see them, and do not take what someone else left.'");
    addTopic("the hill", "@D@She looks past the oak toward "
        "the bare rise. @S@'The frame is older than I am. "
        "The memorial stone is newer. I keep the path clear "
        "because people visit the names, not because anyone "
        "uses the gallows.'");
    addTopic("the names", "@S@'Two watchmen died in a storm "
        "before the keep was repaired. Their names are on "
        "the stone because their families asked for a marker. "
        "I do not add a name without asking the people who "
        "will read it.'");
    addTopic("the lantern", "@D@Erieth turns the brass trimmer "
        "in her palm. @S@'A small light is enough here. The "
        "harbor signal has another purpose, and another keeper. "
        "This one helps a tired traveler find the stone step.'");
    addTopic("the travelers", "@S@'Drovers stop to water their "
        "teams. Children leave smooth stones. A few people "
        "just stand and listen to the stream. I do not ask "
        "what they are remembering.'");
    addTopic("your mantle", "@D@She touches the neat repair "
        "at her shoulder. @S@'A farm child tore it on a fence "
        "and brought it back with a pocket full of thread. "
        "The repair is not pretty. It is sturdy, and the "
        "child was proud to have helped.'");

    addResponse("first conversation", "What is this shrine for?",
        "@D@Erieth sets the shears beside the lantern. "
        "@S@'A moment of quiet, if you want it. The road can "
        "be loud even when nobody speaks. Leave an offering "
        "if you choose, but it is not required.'");
    addResponseTopic("first conversation", "What is this shrine for?",
        "the shrine");
    addResponse("first conversation", "Was anyone hanged here?",
        "@D@She shakes her head and points to the stone marker. "
        "@S@'The old frame is empty. The names belong to two "
        "watchmen lost in a storm, not to people sentenced "
        "here. Cael can tell you why he keeps the hill watched.'");
    addResponseTopic("first conversation", "Was anyone hanged here?",
        "the hill");
    addResponse("the hill", "Who were the watchmen?",
        "@D@Erieth traces the cut letters without touching them. "
        "@S@'Their families chose the words. I know no more "
        "than the stone says, and I will not invent what it "
        "does not.'");
    addResponseTopic("the hill", "Who were the watchmen?", "the names");
    addResponse("first conversation", "May I leave something?",
        "@D@She opens her palm toward the slate niche. "
        "@S@'A smooth stone or a little grain is welcome. "
        "Keep the path clear and leave the lantern wick where "
        "it can be reached.'");
    addResponseTopic("first conversation", "May I leave something?",
        "the shrine");
    addResponse("first conversation", "Do many travelers stop?",
        "@D@Erieth listens to the distant clink of harness. "
        "@S@'Enough that I know some of them by the sound of "
        "their teams. Vessa stops when she has time. Most "
        "people remember the pause longer than the words.'");
    addResponseTopic("first conversation", "Do many travelers stop?",
        "the travelers");
    addResponse("your mantle", "Who mended your mantle?",
        "@D@She smooths the repaired seam. @S@'A child from "
        "Mallowford. I showed them how to knot the thread. "
        "They showed me how to make a patch hold through rain.'");
}
