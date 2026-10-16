import streamlit as st
import pandas as pd
import numpy as np

# चित्रपटांचा डमी डेटा
data = {
    'Title': ['3 Idiots', 'Dangal', 'Chhichhore', 'PK', 'Taare Zameen Par', 
              'Avengers', 'Spider-Man', 'Iron Man', 'Batman', 'Interstellar'],
    'Genre': ['Drama', 'Sports', 'Drama', 'Comedy', 'Drama', 
              'Action', 'Action', 'Action', 'Action', 'Sci-Fi']
}
df = pd.DataFrame(data)

st.title('🎬 Movie Recommendation System')
st.write('तुला आवडणारा चित्रपट निवड आणि इतर ५ चित्रपट सुचव, असा हा सोपा प्रोजेक्ट आहे!')

# युजरसाठी ड्रॉपडाऊन (Selectbox)
selected_movie = st.selectbox('तुला आवडणारा चित्रपट निवड:', df['Title'].values)

if st.button('चित्रपट सुचव (Recommend)'):
    # निवडलेल्या चित्रपटाचा जॉनर (Genre) शोधू
    selected_genre = df[df['Title'] == selected_movie]['Genre'].values[0]
    
    # त्याच जॉनरचे इतर चित्रपट फिल्टर करू (स्वतःचा चित्रपट वगळून)
    recommendations = df[(df['Genre'] == selected_genre) & (df['Title'] != selected_movie)]['Title'].head(5)
    
    st.subheader('तुझ्यासाठी ५ बेस्ट सजेशन्स:')
    if len(recommendations) > 0:
        for i, movie in enumerate(recommendations, 1):
            st.write(f"{i}. {movie}")
    else:
        st.write("सध्या या कॅटेगरीत इतर चित्रपट उपलब्ध नाहीत.")