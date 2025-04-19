/*
  ==============================================================================

    AdditionComponent.h
    Created: 14 Apr 2025 10:15:31pm
    Author:  olivier

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ComponentPerso.h"

//==============================================================================
/*
*/
class AdditionComponent  : public ComponentPerso
{
public:
    AdditionComponent();
    ~AdditionComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void setSelected(bool selected);

private:

    bool isSelected = false;




    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdditionComponent)
};
