//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("the accepted sigil", "@D@Galadhel meets your gaze "
        "without looking away. @S@'My King and Queen accepted my "
        "sigil. I have not abandoned the people who need us, even "
        "if the path I follow is no longer the one you expected.'");
    addTopic("the oath", "@S@'I know what I said in the stronghold. "
        "I meant it. I also know the cost is not yet clear to me. "
        "I will not pretend certainty where I have none.'");
    addTopic("trust", "@D@Her expression softens. @S@'You do not "
        "have to agree with my choice. I ask you to trust that I "
        "made it honestly, and that I am still here beside you.'");
    addTopic("the chasm between us", "@D@Galadhel looks down for "
        "a moment. @S@'I know something has changed between us. "
        "I do not want that distance, but I cannot pretend my "
        "choice was yours to make.'");
    addTopic("what moved me", "@S@'I was moved to act. I cannot "
        "give you a clearer reason than that, and I will not invent "
        "one to make the decision easier to accept.'");
    addTopic("still serving", "@D@She meets your gaze. @S@'I have "
        "not abandoned the Aegis, the kingdom, or the people who "
        "need us. I am still here, doing what I can.'");
    addTopicInterjection("still serving",
        "/areas/argalen-keep/characters/halgaladh/halgaladh.c",
        "our oath", 1);
    addTopic("uncertain cost", "@S@'I do not know what this choice "
        "will cost me. I know that uncertainty is not a reason to "
        "deny what I felt was right.'");
    addTopic("trust without agreement", "@D@Galadhel gives a small "
        "nod. @S@'You can disagree with me and still stand beside "
        "me. I will not ask you to pretend otherwise.'");
    addTopic("following the path", "@S@'The Lord of Water has laid "
        "a path before us. I will take the next step with care, "
        "and answer for what I do along the way.'");
    addTopic("the Lord of Water", "@S@'I believe the Lord of Water "
        "has shown me a path. I do not know where it leads, only "
        "that I must take the next step with care.'");

    addResponse("the accepted sigil", "You rejected your oath.",
        "@S@'I rejected one understanding of it. I still serve "
        "Eledhel and those who remain.'");
    addResponseTopic("the accepted sigil",
        "You rejected your oath.", "the oath");
    addResponse("the accepted sigil", "I feel a chasm between us.",
        "@S@'So do I. I would rather speak honestly than pretend "
        "we are of one mind.'");
    addResponseTopic("the accepted sigil",
        "I feel a chasm between us.", "the chasm between us");
    addResponse("the accepted sigil", "I still need you here.",
        "@S@'I am here. I have not left you or the kingdom.'");
    addResponseTopic("the accepted sigil",
        "I still need you here.", "trust");

    addResponse("the chasm between us", "I cannot accept your choice.",
        "@S@'You do not have to accept it now. I ask only that "
        "you judge me by what I do next.'");
    addResponseTopic("the chasm between us",
        "I cannot accept your choice.", "trust");
    addResponse("the chasm between us", "Why did you choose this?",
        "@S@'I have asked myself the same question. I can tell "
        "you what moved me, but I cannot make it a certainty.'");
    addResponseTopic("the chasm between us",
        "Why did you choose this?", "what moved me");

    addResponse("the oath", "Do you regret what you did?",
        "@S@'I do not know enough to regret it. I know only that "
        "it did not feel wrong in that moment.'");
    addResponseTopic("the oath", "Do you regret what you did?",
        "uncertain cost");
    addResponse("the oath", "What did you reject?",
        "@S@'Less than you think. I rejected the conclusion you "
        "have drawn, not every duty I have ever sworn.'");
    addResponseTopic("the oath", "What did you reject?",
        "still serving");
    addResponse("the oath", "What moved you to act?",
        "@S@'I cannot explain it more clearly than this: I was "
        "moved to do it, and it did not feel wrong.'");
    addResponseTopic("the oath", "What moved you to act?",
        "what moved me");
    addResponse("the oath", "What will you do now?",
        "@S@'I will continue to help our people and learn what "
        "this path requires of me.'");
    addResponseTopic("the oath", "What will you do now?",
        "the Lord of Water");
    addResponse("still serving", "But Morwen and Aradin need the Aegis.",
        "@S@'They need us to serve wisely. I have not stopped "
        "serving them or the people we protect.'");
    addResponseTopic("still serving",
        "But Morwen and Aradin need the Aegis.", "the oath");
    addResponse("still serving", "How can I know you are still with us?",
        "@S@'Watch what I do. I cannot make you believe me by "
        "asking you to ignore what you heard.'");
    addResponseTopic("still serving",
        "How can I know you are still with us?", "trust");
    addResponse("what moved me", "Do you know why it felt right?",
        "@S@'No. I know only that the Lord of Water has shown "
        "me a path, not what every step will demand.'");
    addResponseTopic("what moved me",
        "Do you know why it felt right?", "the Lord of Water");
    addResponse("uncertain cost", "Does not that frighten you?",
        "@S@'It does. Fear is not proof that I chose wrongly, "
        "but I will not pretend I feel none.'");
    addResponseTopic("uncertain cost",
        "Does not that frighten you?", "following the path");
    addResponse("following the path", "What if the path is wrong?",
        "@S@'Then I must be willing to listen, learn, and answer "
        "for my choices. I do not claim to be beyond error.'");
    addResponseTopic("following the path",
        "What if the path is wrong?", "trust");
    addResponse("trust", "I understand, though I disagree.",
        "@S@'That is all I ask. We can disagree and still stand "
        "together.'");
    addResponseTopic("trust", "I understand, though I disagree.",
        "trust without agreement");
    addResponse("trust", "I cannot promise that yet.",
        "@S@'Then let me earn it through what I do next.'");
    addResponseTopic("trust", "I cannot promise that yet.",
        "the Lord of Water");
    addResponse("trust without agreement", "What do you need from me?",
        "@S@'Stay honest with me. If you see me losing my way, "
        "say so. I would rather hear the truth than be comforted.'");
    addResponseTopic("trust without agreement",
        "What do you need from me?", "trust");
    addResponse("the Lord of Water", "Did he command you to do this?",
        "@S@'I will not claim more than I know. I felt moved to "
        "act, and I am still trying to understand what that means.'");
    addResponseTopic("the Lord of Water",
        "Did he command you to do this?", "what moved me");
    addResponse("the Lord of Water", "Will you tell me what happens?",
        "@S@'When I understand it better, I will. For now, I ask "
        "you not to mistake uncertainty for disloyalty.'");
    addResponseTopic("the Lord of Water",
        "Will you tell me what happens?", "following the path");
}
