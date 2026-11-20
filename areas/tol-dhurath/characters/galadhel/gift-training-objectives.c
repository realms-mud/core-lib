//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("training objectives", "@D@Galadhel studies the notes "
        "spread across the table. @S@'I know the gift exists, and "
        "I know I possess it. I still cannot say that I have made "
        "the progress this group needs.'");
    addTopic("impatient progress", "@S@'I want this to matter. "
        "The danger outside these walls is growing, and I do not "
        "know how long we can afford to study without results.'");
    addTopic("learning by unlearning", "@D@She gives a rueful "
        "smile. @S@'Aglaradan taught me that learning archery "
        "meant correcting habits I thought were already sound. "
        "Perhaps this gift will demand the same humility.'");
    addTopic("different methods", "@S@'We keep trying to explain "
        "the gift in one language. Duna speaks of it as art; "
        "Halgaladh wants a method. Perhaps each of us must find "
        "a way that fits.'");
    addTopicInterjection("different methods",
        "/areas/tol-dhurath/characters/halgaladh/halgaladh.c",
        "his method", 1);
    addTopic("the urgency", "@D@Her gaze moves to the windows. "
        "@S@'I feel that we are running out of time. I cannot "
        "prove it, but ignoring that feeling will not make it go away.'");
    addTopic("a teacher's patience", "@S@'I can be patient when "
        "I teach archery because I understand what I am teaching. "
        "Here I am still a student, and I have to remember that.'");

    addResponse("training objectives", "What do you hope to learn?",
        "@S@'Enough to make this gift useful against the enemies "
        "who wield it. I would also like to understand what it "
        "asks of each of us.'");
    addResponseTopic("training objectives",
        "What do you hope to learn?", "impatient progress");
    addResponse("training objectives", "Have you learned anything yet?",
        "@S@'I have learned how much I do not know. That is useful, "
        "but it is not the answer I hoped to bring to this meeting.'");
    addResponseTopic("training objectives",
        "Have you learned anything yet?", "learning by unlearning");
    addResponse("training objectives", "Why are you so restless?",
        "@S@'Because our enemies are not waiting for us to become "
        "comfortable with this power.'");
    addResponseTopic("training objectives", "Why are you so restless?",
        "the urgency");

    addResponse("impatient progress", "Would you abandon the lessons?",
        "@S@'I have considered it. I also know the gift may be "
        "the difference between surviving and losing more people.'");
    addResponseTopic("impatient progress",
        "Would you abandon the lessons?", "a teacher's patience");
    addResponse("impatient progress", "What would count as progress?",
        "@S@'A result we can use, or even a clear understanding "
        "of why one approach fails. I need something more than "
        "another hour of uncertainty.'");
    addResponseTopic("impatient progress",
        "What would count as progress?", "different methods");

    addResponse("learning by unlearning", "How did you handle that?",
        "@S@'I listened to my teacher, accepted correction, and "
        "kept practicing. I can do that again, even if I dislike "
        "being a beginner.'");
    addResponseTopic("learning by unlearning",
        "How did you handle that?", "a teacher's patience");
    addResponse("different methods", "Should we stop looking for rules?",
        "@S@'Not entirely. We should share what we learn, but "
        "we must not assume that one person's method belongs "
        "to everyone.'");
    addResponseTopic("different methods",
        "Should we stop looking for rules?", "training objectives");
    addResponse("the urgency", "What can I do to help?",
        "@S@'Tell us what you discover, even if it is only a "
        "small thing. We cannot build on knowledge we keep to "
        "ourselves.'");
    addResponseTopic("the urgency", "What can I do to help?",
        "different methods");
    addResponse("a teacher's patience", "Can you teach the others?",
        "@S@'Not yet. I can help us practice, but I will not "
        "pretend to be an expert in a power I barely understand.'");
    addResponseTopic("a teacher's patience",
        "Can you teach the others?", "training objectives");
}
