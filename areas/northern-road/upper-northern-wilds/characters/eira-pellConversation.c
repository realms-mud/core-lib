//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Eira turns a loose stone "
        "until it sits flat in the ring. @S@'The ridge is not "
        "a place to hurry. If you have come to look, look. If "
        "you have come to take, say so plainly and save us both "
        "the performance.'");
    addTopic("the three mounds", "@S@'Three families were buried "
        "here before the road had a name. The western mound is "
        "sealed, the northern one is sealed, and the eastern "
        "one was opened long ago. I know the difference between "
        "a settled stone and a disturbed one.'");
    addTopic("the opened mound", "@D@She looks toward the eastern "
        "mound without turning her head. @S@'It was opened "
        "before my father's time. The stones were put back, "
        "but the door was not. I keep the path clear so no one "
        "falls in by accident. I cannot make the dead unburied.'");
    addTopic("the names", "@S@'The names are cut inside the "
        "western ring where rain cannot reach them. I do not "
        "read them aloud. Families visit when they are ready, "
        "not when a stranger asks for a story.'");
    addTopic("your father", "@D@Eira presses the mallet into "
        "her palm. @S@'He kept the ridge before me. He taught "
        "me to reset a stone without changing its place, and "
        "to leave a question unanswered if the answer belongs "
        "to someone else.'");
    addTopic("the offerings", "@S@'People leave flat stones, "
        "thread, and little carved things. I move them only "
        "when they block the drainage. The rain carries enough "
        "away without my help.'");

    addResponse("first conversation", "Which mound was opened?",
        "@D@Eira tilts her mallet toward the eastern mound. "
        "@S@'The eastern one. The entrance is loose, but the "
        "other two are sealed. Keep to the ring if you only "
        "mean to look.'");
    addResponseTopic("first conversation",
        "Which mound was opened?", "the opened mound");
    addResponse("first conversation", "Who is buried here?",
        "@D@She rests one hand on the nearest ring of stones. "
        "@S@'Three households, by the oldest account. Their "
        "names remain in the stone. I will not make a show "
        "of reading them.'");
    addResponseTopic("first conversation", "Who is buried here?",
        "the names");
    addResponse("the three mounds", "Why guard a place so old?",
        "@D@Eira sets the mallet down beside her knee. "
        "@S@'Because people are still capable of being hurt "
        "by what is done to their dead. Age does not make "
        "a grave ownerless.'");
    addResponse("the opened mound", "Can I go inside?",
        "@D@She studies the shifted lintel before answering. "
        "@S@'The roof is uncertain. I will not tell you it is "
        "safe. If you insist, take a light and do not touch "
        "the stones holding the lintel.'");
    addResponse("first conversation", "Who taught you this work?",
        "@D@Her thumb traces the worn handle of the mallet. "
        "@S@'My father. He was a patient man until someone "
        "moved a grave marker to widen a cart track.'");
    addResponseTopic("first conversation", "Who taught you this work?",
        "your father");
    addResponse("your father", "Did he keep the ridge alone?",
        "@D@Eira shakes her head and says, @S@'No. His sister "
        "kept the names and I kept the path. "
        "The work was shared, as it should be.'");
    addResponse("first conversation", "May I leave an offering?",
        "@D@She gestures to a dry patch beside the outer ring. "
        "@S@'If you leave it where rain can carry nothing into "
        "the graves, yes. A stone is enough.'");
    addResponseTopic("first conversation", "May I leave an offering?",
        "the offerings");
    addResponse("the names", "Could you tell me one name?",
        "@D@Eira's expression closes, but not unkindly. "
        "@S@'Not today. Come back with someone who belongs "
        "to this ridge.'");
}
