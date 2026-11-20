//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("visited by vilias", "@D@You sit beside the waterfall "
        "and pool where you have come to find a little peace. "
        "The sense that you are no longer alone draws your attention "
        "to Vilias. @S@'In truth, I do not know anymore... Perhaps "
        "I find solace in your company.'");
    addTopic("the accusation", "@D@Vilias does not turn away from "
        "your accusation. @S@'I deserve that. I... Damn it. Was "
        "what I did really so terrible? Death was coming for them. "
        "I saw no other way to save all of them from...'");
    addTopic("the choice", "@D@She falters before finishing the "
        "thought. The old certainty is gone, but the choice she "
        "made still stands between you. @S@'I saw no other way.'");
    addTopic("what she lost", "@D@Anger flashes across Vilias's "
        "face. Her answer cuts sharply, then softens into a weary "
        "confession. @S@'Indeed! I bring love and happiness in my "
        "wake! The last time I listened to my soul, allowed my "
        "heart to feel, it was ripped out and dashed on the rocks "
        "at my feet. My song was a melody of shaping, of bringing "
        "harmony to the children. I brought courage to the craven, "
        "the ability to dream and to love. I truly was Hope. And "
        "now? All of that was stolen from me. Now, I am vengeance. "
        "I am anger, spite, hatred... I am nothing.'");
    addTopic("the shell", "@D@Her anger subsides, leaving a "
        "hollow weariness. @S@'All that is left of me is this "
        "shell of being, only scarcely caring, devoid of humanity. "
        "Part of me is disgusted by what I have become while part "
        "of me likes it. That small part is growing, occasionally "
        "coming to the forefront. Were it not for you, I may well "
        "have already fallen. During my pressuring of you, "
        "something inside me broke. That was the day I learned "
        "that I hate myself.'");
    addTopic("the pool", "@D@Vilias recoils from your sympathy. "
        "@S@'To the abyss with your sorrow! To the abyss with "
        "healing, and to the abyss with this accursed pool. Only "
        "fools hope. In the end, it will betray you as I have.' "
        "She screams and strikes the water. When the ripples "
        "settle, she is gone.");

    addResponse("visited by vilias", "Why have you come?",
        "@S@'In truth, I do not know anymore. Perhaps I find "
        "solace in your company.'");
    addResponseTopic("visited by vilias",
        "Why have you come?", "the choice");
    addResponse("visited by vilias",
        "You need to torment your plaything to feel better?",
        "@S@'I deserve that. Was what I did really so terrible? "
        "Death was coming for them. I saw no other way to save "
        "all of them from...'");
    addResponseTopic("visited by vilias",
        "You need to torment your plaything to feel better?",
        "the accusation");

    addResponse("the choice", "You saw no other way because you are blind.",
        "@S@'Indeed! I bring love and happiness in my wake!' "
        "Anger flashes across her face, then she sighs. "
        "@S@'The last time I listened to my soul, allowed my "
        "heart to feel, it was ripped out and dashed on the rocks "
        "at my feet.'");
    addResponseTopic("the choice",
        "You saw no other way because you are blind.", "what she lost");
    addResponse("the choice", "What did you bring before vengeance?",
        "@S@'My song was a melody of shaping, of bringing "
        "harmony to the children. I brought courage to the "
        "craven, the ability to dream and to love. I truly was "
        "Hope.'");
    addResponseTopic("the choice",
        "What did you bring before vengeance?", "what she lost");

    addResponse("what she lost", "I like Hope better.",
        "@S@'All that is left of me is this shell of being, "
        "only scarcely caring, devoid of humanity. Part of me "
        "is disgusted by what I have become while part of me "
        "likes it. That small part is growing.'");
    addResponseTopic("what she lost", "I like Hope better.",
        "the shell");
    addResponse("what she lost", "You are more than your anger.",
        "@S@'Were it not for you, I may well have already fallen. "
        "During my pressuring of you, something inside me broke. "
        "That was the day I learned that I hate myself.'");
    addResponseTopic("what she lost",
        "You are more than your anger.", "the shell");

    addResponse("the shell",
        "I do not know why you tell me this. I would heal you if I could.",
        "@S@'To the abyss with your sorrow! To the abyss with "
        "healing, and to the abyss with this accursed pool. Only "
        "fools hope. In the end, it will betray you as I have.'");
    addResponseTopic("the shell",
        "I do not know why you tell me this. I would heal you if I could.",
        "the pool");
}
