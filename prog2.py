#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import pandas as pd
import seaborn as sns
import numpy as np


# In[ ]:


df=pd.read_csv("P2_mov.csv")


# In[ ]:


df.shape


# In[ ]:


df.head()


# In[ ]:


df.info()


# In[ ]:


for i in df.columns:
    print(i," ",type(df[i][0]))


# In[ ]:


df.describe()


# In[ ]:


df.columns


# In[ ]:


df.index


# # DATA Cleaning

# ### Handling missing values 

# In[ ]:


for col in df.columns:
    print(col,"  ",df[col].isna().sum())


# In[ ]:


df['runtime'].fillna(df['runtime'].mean(),inplace=True)


# In[ ]:


df['homepage'].fillna('source_unknown',inplace=True)


# In[ ]:


for c in ['homepage','runtime']:
    print(c,"  ",df[col].isna().sum())


# ## Data Integration

# In[ ]:


df1=pd.read_csv("res.csv",low_memory=False)


# In[ ]:


df1.head()


# In[ ]:


df_new=pd.merge(df,df1,on="original_title")


# In[ ]:


df_new.head()


# In[ ]:


df=df_new


# In[ ]:


df.columns


# ## Data Transformation

# ### Normalization

# In[ ]:


print(df["runtime_y"].min(),df["runtime_y"].max())


# In[ ]:


df["runtime_y"]


# In[ ]:


df["runtime_y"]=((df["runtime_y"]-df["runtime_y"].min())/(df["runtime_y"].max()-df["runtime_y"].min()))*10


# In[ ]:


print(df["runtime_y"].min(),df["runtime_y"].max())


# In[ ]:


print(df["budget_x"].min(),df["budget_x"].max())


# In[ ]:


df['budget_x']=((df['budget_x']-df['budget_x'].min())/(df['budget_x'].max()-df['budget_x'].min()))*100


# In[ ]:


df['budget_x']


# ### Adding extra column

# In[ ]:


df['profit']=df.apply(lambda row:row['revenue_x']-row['budget_x'] ,axis=1)


# ### Changing data types

# In[ ]:


df['release_date_x'] = pd.to_datetime(df['release_date_x'], format = '%Y-%m-%d', errors='coerce')
type(df['release_date_x'][0])


# In[ ]:


df['release_date_y'] = pd.to_datetime(df['release_date_y'], format = '%Y-%m-%d', errors='coerce')
type(df['release_date_y'][0])


# ## Data Reduction 

# In[ ]:


df.columns


# In[ ]:


df.shape[1]


# In[ ]:


df.head(2)


# In[ ]:


df.corr()


# In[ ]:


df.drop(['id_x','popularity_x','runtime_x','vote_average_x','vote_count_x','Unnamed: 0',
         'budget_y','id_y','revenue_y','vote_average_y','runtime_y','production_countries_x',
         'spoken_languages_x','spoken_languages_y','budget_y','original_language_y','release_date_y'],axis=1)


# In[ ]:


df.columns


# In[ ]:


df.shape[1]


# ## Data Discretization

# In[ ]:


df['budget_x'].tail()


# In[ ]:


df['budget_range'] = pd.cut(x=df['budget_x'], bins=[-1,10,1000,10000,100000000000], labels=['No budget','Low', 'Medium', 'High'])


# In[ ]:


df['budget_range'].tail()


# In[ ]:





# ## Data Visualization

# In[ ]:


import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')


# In[ ]:


x=np.array(df['vote_average_x'])
y=np.array(df['vote_count_x'])


# In[ ]:


plt.xlabel('vote_average')
plt.ylabel('vote_count')
plt.title('Votes')
plt.scatter(x,y)


# In[ ]:


x2=np.array(df['revenue_x'])[:200]
y2=np.array(df['vote_average_x'])[:200]
plt.xlabel('revenue')
plt.ylabel('vote_average')
plt.title('Line Plot')
plt.plot(x2,y2)


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




