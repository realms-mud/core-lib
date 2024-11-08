//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private mapping Questionnaire = ([]);
private string *QuestionList = ({});
private string CurrentQuestion;
private string *Results = ({});
private int TestTaken = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    Dictionary = load_object("/lib/dictionaries/backgroundDictionary.c");
    if (!Dictionary)
    {
        raise_error("personalityTraitQuestionnaire: ERROR - The background "
            "dictionary is not present!\n");
    }

    AllowUndo = 0;
    HasDescription = 0;
    TestTaken = 0;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Questionnaire = Dictionary->personalityQuestionnaire();
    if (sizeof(Questionnaire))
    {
        QuestionList = sort_array(m_indices(Questionnaire), (: $1 > $2 :));

        Description = "Personality Test\n\n" +
            configuration->decorate(Questionnaire[QuestionList[0]]["question"],
                "description", "selector", colorConfiguration);

        Data = Questionnaire[QuestionList[0]]["answers"];
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    Results += ({ Data[selection]["type"] });

    int ret = sizeof(QuestionList);
    QuestionList -= ({ QuestionList[0] });
    if (sizeof(QuestionList))
    {
        Description = "Personality Test\n\n" +
            configuration->decorate(Questionnaire[QuestionList[0]]["question"],
                "description", "selector", colorConfiguration);

        Data = Questionnaire[QuestionList[0]]["answers"];
    }
    else
    {
        TestTaken = 1;
        Dictionary->updateUserPersonality(User, Results);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *selection()
{
    return Results;
}

/////////////////////////////////////////////////////////////////////////////
public int testTaken()
{
    return TestTaken;
}
