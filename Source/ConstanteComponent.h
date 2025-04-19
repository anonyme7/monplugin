/*
  ==============================================================================

    Constante.h
    Created: 19 Apr 2025 9:46:49am
    Author:  olivier

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ConstanteComponent  : public juce::Component
{
public:
    ConstanteComponent();
    ~ConstanteComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void mouseDown(const juce::MouseEvent& event) override;

private:

    bool isSelected = false;

    juce::Colour borderColour;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ConstanteComponent)
};
