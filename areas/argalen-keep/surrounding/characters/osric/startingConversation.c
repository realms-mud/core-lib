//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Father Osric looks up from "
        "his reading and offers a warm, if weary, smile. "
        "@S@'Welcome, child. Whether you seek solace or simply "
        "shelter from the road, you are welcome here.'");
    addTopic("the chapel", "@S@'I came here as a young man, full "
        "of certainty about the world.' @D@He chuckles softly. "
        "@S@'The years have a way of replacing certainty with "
        "questions, but I find the questions more honest.' @D@His "
        "expression turns more serious. @S@'Of late, I have felt "
        "the village growing anxious over things no one has "
        "verified. We should attend to one another before we "
        "mistake unease for evidence.'");
    addTopic("daily work", "@D@Osric closes his book and sets it "
        "beside a neatly folded cloth. @S@'I open the chapel at "
        "first light, tend the lamps, and keep a little food for "
        "anyone who arrives too ashamed or too tired to ask. Most "
        "days, that is the work that matters.'");
    addTopic("the well", "@D@Osric's brow furrows. @S@'The well "
        "water tasted of iron after the last heavy rain. Harlan "
        "checked the field drain, and I have asked the village to "
        "use the lower pump until we understand why. A small "
        "precaution is not a prophecy.'");

    addResponse("first conversation", "What is this place?",
        "@S@'This is a humble chapel, dedicated to the light that "
        "guides us through darkness. I have tended it for nearly "
        "thirty years now.' @D@He gazes at the stained glass with "
        "evident affection. @S@'It is not grand, but it serves "
        "its purpose well enough.'");
    addResponseTopic("first conversation", "What is this place?",
        "the chapel");
    addResponse("first conversation", "What do you do for the village?",
        "@D@You ask how Osric serves people who come through the chapel.");
    addResponseTopic("first conversation",
        "What do you do for the village?", "daily work");
    addResponse("first conversation", "I could use some guidance.",
        "@D@Osric nods slowly, his expression growing thoughtful. "
        "@S@'Then you have come to the right place. Sit, and tell "
        "me what weighs on your mind. I find that burdens shared "
        "are burdens halved.'");

    addResponse("the chapel", "What should we do about the west road?",
        "@D@Osric folds his hands. @S@'Ask the people who were "
        "there. A careful account can protect both the village "
        "and the travelers who use that road.'");
    addResponseTopic("the chapel",
        "What should we do about the west road?", "daily work");
    addResponse("daily work", "Is something wrong with the well?",
        "@D@Osric nods toward the pump. @S@'The water changed "
        "after the rain, but we have a clean source nearby. We "
        "are checking the drain before we decide on a cause.'");
    addResponseTopic("daily work", "Is something wrong with the well?",
        "the well");
    addResponse("the well", "Can I help?",
        "@S@'You can carry a clear report to the keep, or help "
        "Harlan check the channel after the ground dries. No "
        "one needs to risk a fall in the mud.'");
    addResponseTopic("the well", "Can I help?", "daily work");
}
