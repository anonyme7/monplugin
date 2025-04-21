/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AdditionComponent.h"
#include "ConstanteComponent.h"

//==============================================================================
/**
*/
class MonpluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MonpluginAudioProcessorEditor (MonpluginAudioProcessor&);
    ~MonpluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void mouseDown(const juce::MouseEvent& event) override;
    void selectComponent(juce::Component* component);
   

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MonpluginAudioProcessor& audioProcessor;

    juce::OwnedArray<ComponentPerso> components; // Liste unifiée pour tous les composants
    juce::Component* selectedComponent = nullptr;

   

    juce::Slider gainSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;

    

    juce::AudioProcessorValueTreeState& apvts;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MonpluginAudioProcessorEditor)
};
