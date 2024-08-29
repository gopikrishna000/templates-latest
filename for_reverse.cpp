<snippet>
	<description>reverse for loop</description>
	<content><![CDATA[for (int ${2:i} = ${3:n - 1}; ${4:$2 >= 0} ; $2${5:--}) {
	${1: int}
}]]></content>
	<tabTrigger>forr</tabTrigger>
	<scope>(source.c | source.objc | source.c++ | source.objc++) - meta.preprocessor.include - comment - string</scope>
</snippet>
